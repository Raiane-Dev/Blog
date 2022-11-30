import { useState } from 'react';
import { Row, Layout, Menu, Typography, Button, Input, Col, Form, Avatar } from 'antd';
import type { MenuProps } from 'antd';
import { useNavigate } from 'react-router-dom';
import {
  HeatMapOutlined, MacCommandOutlined,
  MessageOutlined, CodeSandboxOutlined, ShareAltOutlined,
  SettingOutlined, QuestionCircleOutlined, SearchOutlined, UserOutlined
} from '@ant-design/icons';

const { Header, Content } = Layout;

function _Navbar()
{
  return (
    <>
    <Row align='top' justify='space-between'>
        <Col span={18}>
            <Form
                name="search_posts"
                labelCol={{ span: 8 }}
                wrapperCol={{ span: 16 }}
                initialValues={{ remember: true }}
                autoComplete="off"
            >
                <Form.Item
                name="search"
                >
                <Input 
                    placeholder="Search" 
                    type="text"
                    size="small"
                    className='wrapper-input'
                     prefix={<SearchOutlined />} 
                    />
                </Form.Item>
            </Form>
            </Col>
            <Col span={4}>
            <Avatar size="large" icon={<UserOutlined />} />
            </Col>

        </Row>
    </>
  );
}

export default _Navbar;
